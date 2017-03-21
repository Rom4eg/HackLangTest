<?hh //strict

namespace Core\Exception\Error4xx;

use Core\Exception\Interfaces\IError4xx as err4;

class NotFound extends \LogicException implements err4\IError400Base{
    protected int $code = 404;
    protected string $message = "<h1><center>NOT FOUND</center></h1>";
}

class BadRequest extends \LogicException implements err4\IError400Base{
    protected int $code = 400;
    protected string $message = "<h1><center>BAD REQUEST</center></h1>";
}
