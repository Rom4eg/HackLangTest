<?hh //strict

namespace Core\Routing\Route;

use Core\Http\Request as request;
use Core\Http\Response as response;
use Core\Http\Interfaces\IResponse as iresponse;
use Core\Generics\Interfaces\IView as iview;

class Route{

    public string $name;
    public string $regex;
    public iview\IView $view_obj;
    public mixed $callback;

    public function __construct(string $regex, string $name, iview\IView $view_obj){
        $this->name = $name;
        $this->regex = $regex;
        $this->view_obj = $view_obj;
        $this->callback = inst_meth($view_obj, 'dispatch');
    }
}
