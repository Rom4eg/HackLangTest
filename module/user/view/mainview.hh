<?hh //strict

namespace Module\User\View\MainView;

use Core\Generics\TemplateView as view;
use Core\Http\Request as request;
use Core\Http\Response as resp;
use Core\Http\Interfaces\IResponse as iresponse;

class MainView extends view\TemplateView{

    public string $tpl_name = "user/templates/test.html";

    public function view(): iresponse\ITemplateResponse{
        $args = new Map(null);
        return new resp\TemplateResponse($args);
    }
}
