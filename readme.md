# Model Definition Package (MDP)

**Proposed by:** Richard Haberkern  
**Contact:** rmhaberkern@gmail.com  

*Free for evaluation. Commercial use requires permission. See `LICENSE.md` for more information.*

---

## Overview

The Model Definition Package (MDP) defines a machine-readable contract for embedded AI models.

It specifies model identity, interface semantics, behavioral intent, state assumptions, and degraded operation rules in a structured format suitable for deterministic tooling and embedded system integration.

MDP is part of the EmbeddedX Platform and is designed to operate alongside:

- MRD (Machine Readable Datasheet) for hardware definition
- EIL (Embedded Intelligence Layer) for EdgeAI runtime execution and signal binding
- EIP (Embedded Intelligence Package) for EdgeAI deployment packaging

## Scope

MDP defines the model contract only.

It does not define:

- hardware mappings or registers
- runtime scheduling
- application-specific logic
- training pipelines
- deployment packaging

Those responsibilities belong to other system components.

## Purpose

MDP standardizes how AI models are defined for embedded systems.

It enables:

- portable model definitions
- consistent interface structure
- deterministic integration
- validation through schema and tooling

## Design Principles

### Application Neutral

Models are defined as general capabilities such as prediction, tracking, or anomaly detection.
They are not tied to a specific product or use case.

### Strong Interface Definition

All inputs and outputs are explicitly defined with:

- data types
- units
- required or optional status
- optional constraints

### Degraded Operation

Models define how they behave when inputs are missing or incomplete.
Systems are expected to continue operating within defined limits.

### Separation of Responsibilities

| Component | Responsibility |
|----------|---------------|
| MRD | Hardware definition |
| MDP | Model definition |
| EIL | Runtime execution |
| EIP | Deployment packaging |

## Repository Structure

- spec contains the formal specification
- schema contains the JSON validation schema
- examples contains reference models
- docs contains integration guidance
- tools contains simple validation utilities

## Included Reference Models

This repository includes three reference models:

- generic-target-alignment
- generic-anomaly-monitor
- generic-time-series-predictor

These examples are intentionally application-neutral and are intended to demonstrate how MDP can describe different model classes without binding them to a specific product or hardware platform.

## Compliance Levels

MDP defines two initial compliance levels.

### MDP Level 1

Level 1 is the minimum compliant document level.

A Level 1 MDP document includes:

- required top-level fields
- defined input and output interfaces
- behavior section
- degraded operation section
- traceability section
- schema-valid structure

Level 1 is intended for:

- simple model definitions
- documentation and review
- baseline tool compatibility

### MDP Level 2

Level 2 extends Level 1 with stronger implementation detail.

A Level 2 MDP document includes everything in Level 1, plus:

- state definition where applicable
- constraints section
- degraded operation rules beyond minimum required inputs
- stronger timing guidance
- more complete signal metadata
- artifact references where appropriate

Level 2 is intended for:

- production-oriented integration
- richer validation
- stronger portability across runtimes

A document may claim Level 2 compliance only if all Level 1 requirements are met first.

## Compliance Matrix

| Requirement | Level 1 | Level 2 |
|-------------|---------|---------|
| mdp_version | Required | Required |
| compliance_level | Required | Required |
| model_id | Required | Required |
| model_name | Required | Required |
| model_class | Required | Required |
| description | Required | Required |
| interface | Required | Required |
| behavior | Required | Required |
| degraded_operation.minimum_required_inputs | Required | Required |
| traceability | Required | Required |
| constraints | Optional | Required |
| degraded_operation.rules | Optional | Required if optional inputs exist |
| state | Required for stateful models | Required for stateful models |
| artifact references | Optional | Recommended |
| timing guidance | Optional | Recommended |
| richer signal metadata | Optional | Recommended |

Level 1 is intended for baseline interoperability and review.

Level 2 is intended for stronger tooling, integration review, and production-oriented implementation planning.

## Validation Example

A simple validator script is included in:

tools/validate_mdp.py

Example usage:

```bash
python tools/validate_mdp.py schema/mdp.schema.json examples/generic-target-alignment/model.mdp.json
```

This script performs basic schema validation for MDP documents.

The validator checks schema compliance only.

Runtime correctness against test vectors should be validated separately by the implementation using the example input and output files.

## Python Requirements

The validator example uses a minimal Python dependency set.

Install with:

```bash
pip install -r requirements.txt
```

## Test Vectors

Each reference model includes a small `test_vectors` folder.

These files provide example inputs and expected outputs for simple validation and reference testing.

Test vectors are intended to support:

- runtime verification
- integration checks
- schema and interface review
- example tooling workflows

## Example

See:

examples/generic-target-alignment/model.mdp.json

This example represents a generic predictive alignment model and is not tied to a specific application.

## Status

MDP is an evolving specification intended for embedded AI systems that require portability, clarity, and deterministic behavior.

## License

See LICENSE.md
