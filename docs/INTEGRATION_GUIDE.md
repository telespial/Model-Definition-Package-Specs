# MDP Integration Guide

## Overview

This document explains how MDP models are used within a system.

MDP does not execute models.
It defines the structure and behavior of a model.

Execution and integration are handled by EIL.

## Integration Flow

1. Load model.mdp.json
2. Validate against schema
3. Bind inputs to system signals
4. Bind outputs to system consumers
5. Execute using runtime implementation

## Signal Binding

MDP defines signal structure only.

EIL is responsible for:

- mapping sensors to inputs
- mapping outputs to actuators or logic
- handling missing inputs
- enforcing degraded operation rules

## Degraded Operation

If optional inputs are missing:

- use fallback strategies defined in the model
- maintain minimum required inputs
- continue operation with reduced performance if necessary

## Runtime Implementation

MDP does not require a specific runtime.

Typical implementations:

- lightweight C++ inference layer
- embedded ML runtime
- custom DSP or NPU execution

## Validation

Before use:

- validate JSON structure against schema
- verify required inputs are present
- confirm compatibility with runtime

## Notes

MDP is designed to be simple to integrate and independent of hardware and operating system.
