<?hh

namespace Core\Http\Server;
use Core\Http\Interfaces\IServer as iserver;

final class Server implements iserver\IServer{

    protected static ?Server $inst;
    public Map<string, string> $server_vars;

    protected function __construct(){
        $this->server_vars = new Map($_SERVER);
    }

    public static function makeServer(): Server{
        if(!self::$inst){
            self::$inst = new static();
        }
        return self::$inst;
    }

    public function get(string $name, mixed $default): mixed{
        $inst = self::makeServer();
        if($inst->server_vars->contains(strtoupper($name))){
            return $inst->server_vars->get(strtoupper($name));
        }
        return $default;
    }
}
