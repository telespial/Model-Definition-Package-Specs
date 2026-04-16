# Model Definition Package (MDP)

## Model Metadata for Embedded Inference and Integration

Proposed by: Richard Haberkern  
Contact: rmhaberkern@gmail.com

Free for evaluation. Commercial use requires permission. See license.md for more information.

Part of the [EmbeddedX platform](https://github.com/telespial/EmbeddedX-Specs).

* * *

## Abstract

Model Definition Package (MDP) defines a machine-readable format for embedded Edge AI models, including their interfaces, runtime assumptions, and degraded-operation behavior. The point is to make models portable and easier to integrate across embedded systems.

MDP focuses on model-facing data: inputs, outputs, windows, sampling, behavior metadata, degraded-operation support, runtime assumptions, and deployment constraints. It gives tools a stable description of what a model expects and what it returns.

* * *

## 1. Scope

MDP may describe:

* model identity and version
* model type and purpose
* inputs and outputs
* units and scaling
* sampling assumptions
* window size and data shape
* degraded operation behavior
* runtime constraints
* explainability metadata
* deployment targets

* * *

## 2. Why MDP Matters

Too many embedded models are shipped as opaque binaries with loose notes around them. That makes deterministic integration harder than it should be.

MDP establishes a portable model contract so runtime layers, package formats, and coding systems know exactly what the model expects and what it returns.

* * *

## 3. Relationship to Other Repositories

* [EmbeddedX-Specs](https://github.com/telespial/EmbeddedX-Specs) establishes the umbrella platform
* [Machine-Readable-Datasheets-Specs](https://github.com/telespial/Machine-Readable-Datasheets-Specs) defines hardware capabilities visible to firmware
* [Machine-Readable-Connectivity-Specs](https://github.com/telespial/Machine-Readable-Connectivity-Specs) may help describe signal provenance, scaling paths, and degraded board-level conditions
* [Embedded-Intelligence-Layer-Specs](https://github.com/telespial/Embedded-Intelligence-Layer-Specs) should preserve MDP-defined runtime assumptions
* [AI-Integrated-Coding-System-Spec](https://github.com/telespial/AI-Integrated-Coding-System-Spec) should not generate integration code that contradicts MDP
* [Embedded-Intelligence-Package-Specs](https://github.com/telespial/Embedded-Intelligence-Package-Specs) may package MDP-defined artifacts for deployment

* * *

## 4. Core Principle

If runtime integration depends on it, MDP should be able to express it.

* * *

## License

See `license.md`.
