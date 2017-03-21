<?hh
error_reporting(E_ALL);
ini_set("display_errors", 1);
require_once('core/autoloader.hh');
$autoloader = new Core\Autoloader();

use Core\App as app;

$app = app\Application::getInstance();
$app->start();
