<?hh //strict

namespace Module\ActiveModules;

use Module\User\Urls as user_urls;
use Core\Generics\Interfaces\IUrl as iurl;

class AppModules{
    public Vector<iurl\IUrl> $app_urls;

    public function __construct(){
        $this->app_urls = Vector{
            new user_urls\UserUrls(),
        };

    }
}
