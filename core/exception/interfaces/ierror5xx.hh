<?hh //strict

namespace Core\Exception\Interfaces\IError5xx;

interface IError500Base{
    require extends \LogicException;
}
