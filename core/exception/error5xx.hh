<?hh //strict

namespace Core\Exception\Error5xx;

use Core\Exception\Interfaces\IError5xx as err5;

class InternalServerError extends \LogicException implements err5\IError500Base{
    protected int $code = 500;
    protected string $message = "<h1><center>INTERNAL SERVER ERROR</center></h1>";
}
