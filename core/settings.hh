<?hh // strict

namespace Core\Settings;
final class Settings{

    protected static ?Settings $inst;
    public Map<string, mixed> $config;

    protected function __construct(string $location){
        $this->config = new Map($this->_parseConfig($location));
    }

    public static function load(string $location): Settings{
        if(self::$inst){
            return self::$inst;
        }
        self::$inst = new static($location);
        return self::$inst;
    }

    public static function get(string $name, mixed $default): mixed{
        if(self::$inst?->config?->contains($name)){
            return self::$inst?->config?->get($name);
        }
        return $default;
    }

    private function _parseConfig(string $location): array<string, mixed>{
        $loc = $location.DIRECTORY_SEPARATOR.'config.yaml';
        return yaml_parse_file($loc);
    }
}
