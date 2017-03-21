<?hh

namespace Core\Http\Request;

final class Request{

    protected static ?Request $inst;
    public Map<string, string> $request_vars;

    protected function __construct(){
        $this->request_vars = new Map($_REQUEST);
    }

    public static function getRequest(): Request{
        if(!self::$inst){
            self::$inst = new static();
        }
        return self::$inst;
    }

    public static function get(string $name, mixed $default): mixed{
        $inst = self::getRequest();
        if($inst->request_vars->contains($name)){
            return $inst->request_vars->get($name);
        }
        return $default;
    }
}
