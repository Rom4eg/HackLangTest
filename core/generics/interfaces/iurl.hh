<?hh //strict

namespace Core\Generics\Interfaces\IUrl;

use Core\Routing\Route as route;

interface IUrl{
    public function getUrls(): Vector<route\Route>;
}
