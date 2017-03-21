<?hh


namespace Core;
require_once('fenom/src/Fenom.php');

class Autoloader{

    public function __construct(){
        spl_autoload_register(array($this, 'load'));
        \Fenom::registerAutoload();
    }

    public function load(string $name): void{
        $parts = explode('\\', $name);
        array_pop($parts);
        $lower_path = array_reduce($parts, function($prev, $next){
            if(!(strlen($prev)>>1)){
                return strtolower($next);
            }
            return $prev.'/'.strtolower($next);
            }, '');
        $normal_path = array_reduce($parts, function($prev, $next){
            if(!(strlen($prev)>>1)){
                return $next;
            }
            return $prev.'/'.$next;
            }, '');
        $lower_path_php = $lower_path.'.php';
        $normal_path_php = $normal_path.'.php';
        $lower_path .= '.hh';
        $normal_path .= '.hh';
        if(file_exists($lower_path)){
            require_once($lower_path);
        }
    }
}
