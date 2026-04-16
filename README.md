# Model Definition Package (MDP)

## Model Metadata for Embedded Inference and Integration

Proposed by: Richard Haberkern  
Contact: rmhaberkern@gmail.com

Free for evaluation. Commercial use requires permission. See `license.md` for more information.

Part of the **EmbeddedX specification family**.

**Canonical index:** start at `EmbeddedX-Specs`:
https://github.com/telespial/EmbeddedX-Specs

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

## 3. Relationship to Other Specifications

* **EmbeddedX (umbrella):** https://github.com/telespial/EmbeddedX-Specs
* **MRD:** https://github.com/telespial/Machine-Readable-Datasheets-Specs
* **MRC:** https://github.com/telespial/Machine-Readable-Connectivity-Specs
* **EIL:** https://github.com/telespial/Embedded-Intelligence-Layer-Specs
* **AICS:** https://github.com/telespial/AI-Coding-System-Specs
* **EIP:** https://github.com/telespial/Embedded-Intelligence-Package-Specs

* * *

## 4. Core Principle

If runtime integration depends on it, MDP should be able to express it.

* * *

## License

See `license.md`.
