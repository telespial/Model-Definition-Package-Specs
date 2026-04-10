import json
import sys
from pathlib import Path

try:
    import jsonschema
except ImportError:
    print("Missing dependency: jsonschema")
    print("Install with: pip install jsonschema")
    sys.exit(1)


def load_json(path: Path):
    with path.open("r", encoding="utf-8") as f:
        return json.load(f)


def main():
    if len(sys.argv) != 3:
        print("Usage: python tools/validate_mdp.py <schema.json> <model.mdp.json>")
        sys.exit(1)

    schema_path = Path(sys.argv[1])
    model_path = Path(sys.argv[2])

    if not schema_path.exists():
        print(f"Schema file not found: {schema_path}")
        sys.exit(1)

    if not model_path.exists():
        print(f"Model file not found: {model_path}")
        sys.exit(1)

    try:
        schema = load_json(schema_path)
        model = load_json(model_path)
        jsonschema.validate(instance=model, schema=schema)
    except jsonschema.ValidationError as e:
        print("Validation failed")
        print(f"Message: {e.message}")
        print(f"Path: {'/'.join(str(p) for p in e.absolute_path)}")
        sys.exit(1)
    except jsonschema.SchemaError as e:
        print("Schema error")
        print(f"Message: {e.message}")
        sys.exit(1)
    except json.JSONDecodeError as e:
        print("Invalid JSON")
        print(str(e))
        sys.exit(1)

    print("Validation passed")
    print(f"Model: {model.get('model_id', 'unknown')}")
    print(f"Compliance level: {model.get('compliance_level', 'unknown')}")


if __name__ == "__main__":
    main()
