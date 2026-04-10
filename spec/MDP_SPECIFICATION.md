# Model Definition Package (MDP) Specification

## Abstract

The Model Definition Package (MDP) defines a machine-readable contract for embedded AI models.
It standardizes model identity, interface semantics, behavioral intent, state assumptions, and degraded operation rules in a form suitable for deterministic integration into embedded systems.

MDP is intended to support portability across hardware and software environments by separating model definition from hardware description, runtime binding, and deployment packaging.

## 1. Scope

This specification defines the structure and meaning of an MDP document.

An MDP document shall describe:

- model identity
- model class
- input and output interfaces
- state-related assumptions
- behavioral intent
- degraded operation behavior
- traceability metadata

This specification does not define:

- hardware resources
- pin mappings
- registers
- runtime scheduling
- deployment packaging
- training procedures

Those concerns are handled by adjacent system components.

## 2. Position Within the EmbeddedX Architecture

MDP is one of several contract layers within the EmbeddedX Platform.

### 2.1 Adjacent Components

- MRD (Machine Readable Datasheet)
  Defines hardware-visible resources, constraints, interfaces, registers, and firmware-relevant platform behavior.

- MDP (Model Definition Package)
  Defines the model contract, including interface semantics and behavioral intent.

- EIL (Embedded Intelligence Layer)
  Binds model signals to application signals, executes the model, manages runtime policy, and applies integration logic.

- EIP (Embedded Intelligence Package)
  Packages deployable artifacts, documentation, and implementation outputs.

### 2.2 Separation of Responsibilities

MDP shall remain application-neutral.
MDP shall not encode product-specific routing logic or hardware-specific mappings.
MDP shall not assume a specific MCU, MPU, NPU, operating system, or vendor SDK.

## 3. Design Goals

The design of MDP is guided by the following goals:

### 3.1 Machine Readability

MDP shall be structured for schema validation and deterministic tooling.

### 3.2 Strong Interface Semantics

Inputs and outputs shall carry explicit data type, unit, and requirement information.

### 3.3 Application Neutrality

MDP shall describe generalized model behavior rather than a specific finished application.

### 3.4 Degraded Operation

MDP shall support explicit behavior under missing or partial inputs.

### 3.5 Portability

MDP shall allow the same model definition to be reused across multiple target systems, subject to runtime adaptation by EIL.

## 4. Terminology

### 4.1 Model

A defined computational unit that accepts a declared input set and produces a declared output set according to a specified behavioral intent.

### 4.2 Required Input

An input that must be available for compliant operation of the declared model contract.

### 4.3 Optional Input

An input that may be omitted, provided the declared degraded operation rules remain satisfied.

### 4.4 Degraded Operation

A valid operational mode in which the model continues to function under missing or substituted inputs, with declared effects on behavior, confidence, or performance.

### 4.5 Behavioral Intent

A declaration of the purpose of the model, such as predictive alignment, anomaly detection, time-series prediction, or classification.

## 5. MDP Document Structure

An MDP document shall be represented as a single machine-readable object.

### 5.1 Required Top-Level Fields

An MDP document shall include the following top-level fields:

- mdp_version
- compliance_level
- model_id
- model_name
- model_class
- description
- interface
- behavior
- degraded_operation
- traceability

### 5.2 Optional Top-Level Fields

An MDP document may include:

- state
- constraints
- artifacts

### 5.3 Additional Properties

Implementations claiming compliance with this specification should reject undeclared top-level properties unless an extension mechanism is formally introduced.

## 6. Model Identity

### 6.1 Version

mdp_version shall use semantic versioning in the form MAJOR.MINOR.PATCH.

### 6.2 Identifier

model_id shall be unique within the producing organization or repository context.
It should be stable across documentation and implementation artifacts.

### 6.3 Name

model_name shall provide a human-readable name for the model definition.

### 6.4 Class

model_class shall declare the general behavioral category of the model.

Supported classes may include:

- tracking_prediction
- time_series_prediction
- anomaly_detection
- classification
- regression
- adaptive_reasoning
- hybrid

Additional classes may be introduced by future revisions.

## 7. Interface Definition

### 7.1 General Requirements

The interface section shall define all declared inputs and outputs.

### 7.2 Inputs

Each input shall define:

- name
- data_type
- unit
- required

Each input may additionally define:

- rate_hz
- range
- default_value
- description
- fallback_policy
- degraded_impact

### 7.3 Outputs

Each output shall define:

- name
- data_type
- unit

Each output may additionally define:

- range
- description
- semantic_role

### 7.4 Strong Typing

Signal types shall be explicitly declared.

### 7.5 Units

Numeric signals shall include explicit units or normalized unit declarations.
Units shall not be implied solely by description text.

## 8. State Definition

### 8.1 Purpose

The optional state section describes assumptions about retained model state, temporal windows, and warmup behavior.

### 8.2 Stateful Declaration

If the model relies on historical values, retained context, or temporal aggregation, the model should declare stateful: true.

### 8.3 State Variables

A state variable may be declared to identify retained internal state relevant to integration, verification, or documentation.

### 8.4 Windowing

For temporal models, window_samples should declare the expected number of samples required for a fully informed inference cycle.

## 9. Behavioral Definition

### 9.1 Primary Objective

The behavior section shall declare a primary_objective describing the intended purpose of the model.

### 9.2 Stateful Behavior

The behavior section shall declare whether the model is stateful.

### 9.3 Timing Guidance

The behavior section may specify:

- prediction_horizon_ms
- recommended_cycle_rate_hz
- latency_requirement_ms

These values describe model-level assumptions and do not themselves impose runtime scheduling policy.

### 9.4 Output Semantics

MDP may define semantic descriptions for outputs to clarify intent without binding them to a specific application implementation.

## 10. Constraints

### 10.1 Purpose

The optional constraints section documents implementation-relevant assumptions, such as precision or resource budgets.

### 10.2 Non-Binding Nature

Unless explicitly incorporated into a compliance profile, these constraints are advisory model constraints rather than hardware requirements.

### 10.3 Examples

Constraints may include:

- numeric precision expectations
- memory budget guidance
- maximum compute time guidance

## 11. Degraded Operation

### 11.1 Requirement

All compliant MDP documents shall define minimum_required_inputs.

### 11.2 Purpose

The degraded_operation section defines acceptable operation when optional signals are absent or substituted.

### 11.3 Rules

A degraded-operation rule may define:

- missing input set
- fallback mechanism
- expected effect
- severity

### 11.4 Minimum Viable Operation

The model shall identify the minimum input set required to preserve a valid operational contract.

### 11.5 Confidence Reporting

If a runtime is expected to expose confidence or quality degradation metadata, the document may declare confidence_reporting: true.

## 12. Traceability

### 12.1 Purpose

Traceability metadata supports review, governance, and lifecycle management.

### 12.2 Required Fields

The traceability section shall include:

- author
- organization
- created
- last_modified

### 12.3 Optional References

The document may include source references, design references, or related artifact links.

## 13. Validation

### 13.1 Schema Compliance

An MDP document claiming compliance with this specification shall conform to the corresponding JSON schema.

### 13.2 Semantic Validation

Schema validation alone is not sufficient.
Implementations should also validate:

- signal name uniqueness
- consistency between degraded rules and declared inputs
- consistency between statefulness declarations in state and behavior
- presence of units on numeric signals
- semantic consistency of fallback behavior

## 14. Example Design Pattern

A generic predictive alignment model may define:

- required inputs for target position
- optional inputs for target velocity
- outputs representing recommended alignment adjustments
- degraded operation based on deriving velocity from recent position history

Such a model remains application-neutral.
Its binding to a game, robotic tracker, drone, or actuator system belongs to EIL and not to MDP.

## 15. Conformance

An implementation or document may claim conformance only if:

1. the MDP document conforms to the schema,
2. required fields are present and semantically valid,
3. degraded operation behavior is explicitly declared,
4. the document does not embed hardware-specific or application-binding logic inconsistent with the separation of responsibilities defined in this specification.

## 16. Compliance Levels

This specification defines two initial compliance levels.

### 16.1 MDP Level 1

MDP Level 1 defines the minimum compliant document structure.

A Level 1 MDP document shall include:

- mdp_version
- compliance_level
- model_id
- model_name
- model_class
- description
- interface
- behavior
- degraded_operation
- traceability

A Level 1 document shall:

- conform to the published schema
- define at least one input
- define at least one output
- define minimum_required_inputs
- define required traceability fields

A Level 1 document may omit:

- state
- constraints
- artifacts
- detailed degraded-operation rules beyond the minimum required input set

Level 1 is intended for baseline interoperability and review.

### 16.2 MDP Level 2

MDP Level 2 defines an extended document structure for stronger implementation guidance.

A Level 2 MDP document shall meet all Level 1 requirements.

In addition, a Level 2 document shall include, where applicable:

- state for stateful models
- constraints when implementation assumptions are known
- one or more explicit degraded-operation rules if optional inputs exist
- timing guidance if the model behavior depends on execution rate or prediction horizon

A Level 2 document should also include:

- signal ranges for numeric values where meaningful
- fallback policy metadata for optional inputs
- artifact references for test vectors or reference runtime materials

Level 2 is intended for stronger tooling, integration review, and production-oriented deployment planning.

### 16.3 Compliance Claims

A document shall not claim Level 2 compliance unless it first satisfies all Level 1 requirements.

Claims of compliance should identify both:

- MDP specification version
- compliance level

Example:

MDP Specification 1.0.0, Level 2

For schema purposes, compliance_level is a required field and shall be declared as either:

- Level 1
- Level 2

## 17. Test Vectors

An MDP example or companion artifact set may include test vectors.

Test vectors are not required for Level 1 compliance.

For Level 2 documents, test vectors are recommended where practical.

A test vector set may include:

- sample input data
- expected output data
- descriptive notes about assumptions or operating conditions

Test vectors are intended to support implementation verification and integration review.

## 18. Future Work

Future revisions may define:

- extension mechanisms
- compliance profiles
- quantization descriptors
- formal confidence output semantics
- standardized test vector attachment
- model interchange compatibility layers

## 19. Conclusion

MDP provides a machine-readable model contract for embedded AI systems.
By separating model definition from hardware description, runtime binding, and deployment packaging, MDP enables more portable, reviewable, and deterministic embedded AI integration.
