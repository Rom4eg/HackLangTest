<?hh //strict

namespace Core\Generics\Interfaces\IView;

use Core\Http\Request as request;
use Core\Http\Interfaces\IResponse as iresponse;
use Core\Generics\View as view;

interface IView{
    public function dispatch(request\Request $req): iresponse\IResponse;
    public function view():iresponse\IResponse;
    public function errorView(int $code, string $message): iresponse\IResponse;
}

interface ITemplateView extends IView{
    require extends view\View;
    public function render(Map<string, mixed> $params): string;
}
