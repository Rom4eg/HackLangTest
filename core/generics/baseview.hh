<?hh //strict

namespace Core\Generics\BaseView;

use Core\Generics\Interfaces\IView as iview;
use Core\Http\Interfaces\IResponse as iresponse;
use Core\Http\Request as request;

abstract class BaseView implements iview\IView{

    abstract public function view():iresponse\IResponse;
    abstract public function dispatch(request\Request $req): iresponse\IResponse;
    abstract public function errorView(int $code, string $message): iresponse\IResponse;
}
