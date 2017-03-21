<?hh

namespace Core\App;
/*require_once('twig/lib/Twig/Loader/Filesystem');*/

use Core\Settings as settings;
use Core\Http\Request as request;
use Core\Http\Server as server;
use Core\Routing\Router as router;
use Core\Routing\Route as route;
use Module\ActiveModules as a_modules;
use Core\Exception\Interfaces\IError5xx as err5;
use Core\Exception\Interfaces\IError4xx as err4;
use Core\Http\Interfaces\IResponse as iresp;
use Core\Http\Response as resp;

final class Application{

    public settings\Settings $settings;
    public request\Request $request;
    public server\Server $server;
    protected router\Router $router;
    protected a_modules\AppModules $active_modules;
    public \Fenom $fenom;

    public static ?Application $inst;

    protected function __construct(){
        $settings_location = dirname(__DIR__);
        $this->settings = settings\Settings::load($settings_location);
        $this->request = request\Request::getRequest();
        $this->server = server\Server::makeServer();
        $this->active_modules = new a_modules\AppModules();
        $this->router = new router\Router($this->active_modules->app_urls);

        $base_dir = settings\Settings::get('base_dir', './');
        $this->fenom = new \Fenom(new \Fenom\Provider((string)$base_dir.'/module'));
        $this->fenom->setCompileDir('/tmp');
    }

    public static function getInstance(){
        if(self::$inst){
            return self::$inst;
        }
        return new static();
    }

    public function start(): void{
        $req_url = (string)$this->server->get('request_uri', "");
        $route = $this->router->getMatchedRoute($req_url);
        $resp = $this->execController($route);
        http_response_code($resp->getCode());
        echo $resp->getContent();
    }

    protected function execController(route\Route $route): iresp\IResponse{
        $resp = new resp\Response(500, 'Uncatchbale error.');
        $err_callale = inst_meth($route->view_obj, 'errorView');
        try{
            $resp = call_user_func_array($route->callback, array($this->request));
        } catch (err5\IError500Base $err){
            $resp = call_user_func_array($err_callale, array($err->getCode(), $err->getMessage()));
        } catch (err4\IError400Base $err){
            $resp = call_user_func_array($err_callale, array($err->getCode(), $err->getMessage()));
        } catch (\Exception $err){
            $resp = call_user_func_array($err_callale, array($err->getCode(), $err->getMessage()));
        }
        return $resp;
    }
}
