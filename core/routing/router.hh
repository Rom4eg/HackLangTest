<?hh //strict

namespace Core\Routing\Router;
use Core\Http\Interfaces\IServer as iserver;
use Core\Routing\Route as route;
use Core\Generics\Interfaces\IUrl as iurl;
use Core\Generics\View as view;

class Router{

    public Vector<route\Route> $routes;

    public function __construct(Vector<iurl\IUrl> $urls){
        $this->routes = $this->extractUrls($urls);
    }

    private function extractUrls(Vector<iurl\IUrl> $urls): Vector<route\Route>{
        $tmp = new Vector(null);
        foreach($urls->getIterator() as $mod_urls){
            foreach($mod_urls->getUrls()->getIterator() as $route){
                $tmp->add($route);
            }
        }
        return $tmp;
    }

    public function getMatchedRoute(string $req_route): route\Route{
        $tmp = new route\Route('', 'error', new view\View());
        foreach($this->routes as $route){
            if(preg_match($route->regex, $req_route)){
                $tmp = $route;
                break;
            }
        }
        return $tmp;
    }
}
