<?hh //strict

namespace Core\Generics\View;

use Core\Generics\Interfaces\IView as iview;
use Core\Http\Interfaces\IResponse as iresponse;
use Core\Http\Response as response;
use Core\Http\Request as request;
use Core\Exception\Error4xx as err4;
use Core\Generics\BaseView as bview;
use Core\App as app;

class View extends bview\BaseView implements iview\IView{

    protected app\Application $app;

    public function __construct(){
        $this->app = app\Application::getInstance();
    }

    public function view():iresponse\IResponse{
        throw new err4\BadRequest();
    }

    public function dispatch(request\Request $req): iresponse\IResponse{
        if(method_exists($this, 'view')){
            return call_user_func_array(inst_meth($this, 'view'), array($req));
        }
        throw new err4\NotFound();
    }

    public function errorView(int $code, string $message): iresponse\IResponse{
        return new response\Response($code, '<h1><center>$message</center></h1>');
    }
}
