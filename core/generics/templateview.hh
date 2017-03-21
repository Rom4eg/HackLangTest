<?hh //strict

namespace Core\Generics\TemplateView;
use Core\Generics\View as view;
use Core\Http\Response as response;
use Core\Http\Request as request;
use Core\Settings as settings;
use Core\App as app;
use Core\Generics\Interfaces\IView as iview;
use Core\Http\Interfaces\IResponse as iresp;
use Core\Exception\Error4xx as err4;

class TemplateView extends view\View implements iview\ITemplateView{

    private string $tpl_name = "";

    public function render(Map<string, mixed> $values): string{
        return $this->app->fenom->fetch($this->tpl_name, $values);
    }

    public function dispatch(request\Request $req): iresp\IResponse{
        if(method_exists($this, 'view')){
            $tpl_args = call_user_func_array(inst_meth($this, 'view'), array($req));
            $rendered_tpl = $this->render($tpl_args->getTemplateContent());
            return new response\Response(200, $rendered_tpl);
        }
        throw new err4\NotFound();
    }

    public function view(): iresp\ITemplateResponse{
        return new response\TemplateResponse(new Map(null));
    }
}
