<?hh //strict

namespace Module\User\Urls;
use Core\Routing\Route as route;
use Module\User\View\MainView as main;
use Core\Generics\Interfaces\IUrl as iurl;

class UserUrls implements iurl\IUrl{
    public Vector<route\Route> $urls;

    public function __construct(){
        $this->urls = Vector{
                new route\Route('/^\/$/', 'main', new main\MainView()),
            };
    }

    public function getUrls(): Vector<route\Route>{
        return $this->urls;
    }
}
