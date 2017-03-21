<?hh //strict

namespace Core\Http\Interfaces\IResponse;

interface IResponse{
    public function getCode():int;
    public function getContent(): string;
}

interface ITemplateResponse extends IResponse{
    public function getTemplateContent(): Map<string, mixed>;
}
