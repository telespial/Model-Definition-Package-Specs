# Model Definition Package (MDP)

## A Machine-Readable Model Contract for Embedded EdgeAI Inputs, Outputs, Behavior, and Degraded Operation

Proposed by: Richard Haberkern  
Contact: rmhaberkern@gmail.com

Free for evaluation. Commercial use requires permission. See license.md for more information.

Part of the [EmbeddedX platform](https://github.com/telespial/EmbeddedX-Specs).

* * *

## Abstract

Model Definition Package (MDP) describes what an embedded EdgeAI model expects, what it returns, and how it should behave when conditions are not ideal.

Many embedded models are shipped as files with loose notes around them. That makes integration harder than it needs to be. Engineers still have to figure out sample rates, input shapes, units, scaling, outputs, confidence values, and degraded behavior by reading code or guessing from examples.

MDP puts those model details into a structured format so runtime layers, package systems, and code-generation systems can use the model consistently.

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

A model is not useful in an embedded system until the firmware knows how to feed it, read it, and respond to it safely.

MDP defines those expectations clearly. It helps avoid hidden assumptions in example code, model wrappers, or comments.

* * *

## 3. Relationship to Other Repositories

* [EmbeddedX-Specs](https://github.com/telespial/EmbeddedX-Specs): umbrella platform
* [Machine-Readable-Datasheets-Specs](https://github.com/telespial/Machine-Readable-Datasheets-Specs): describes what the hardware can do
* [Machine-Readable-Connectivity-Specs](https://github.com/telespial/Machine-Readable-Connectivity-Specs): shows how schematics, netlists, BOM files, and board files connect real signals to model inputs
* [Embedded-Intelligence-Layer-Specs](https://github.com/telespial/Embedded-Intelligence-Layer-Specs): should preserve MDP-defined runtime assumptions
* [AI-Integrated-Coding-System-Spec](https://github.com/telespial/AI-Integrated-Coding-System-Spec): should not generate integration code that contradicts MDP
* [Embedded-Intelligence-Package-Specs](https://github.com/telespial/Embedded-Intelligence-Package-Specs): may package MDP-defined artifacts for deployment

* * *

## 4. Core Principle

If firmware needs to feed, run, interpret, or recover from a model, MDP should be able to describe the required behavior.

* * *

## License

See `license.md`.
