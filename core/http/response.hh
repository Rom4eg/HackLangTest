<?hh //strict

namespace Core\Http\Response;

use Core\Http\Interfaces\IResponse as iresponse;

class Response implements iresponse\IResponse{

    protected int $code;
    protected string $content;

    public function __construct(int $code, string $content){
        $this->code = $code;
        $this->content = $content;
    }

    public function getCode(): int{
        return $this->code;
    }

    public function getContent(): string{
        return $this->content;
    }
}

class TemplateResponse extends Response implements iresponse\ITemplateResponse{

    protected Map<string, mixed> $tpl_args;

    public function __construct(Map<string, mixed> $tpl_args){
        parent::__construct(200, '');
        $this->tpl_args = $tpl_args;
    }

    public function getTemplateContent(): Map<string, mixed>{
        return $this->tpl_args;
    }
}
