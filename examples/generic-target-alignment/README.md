# Generic Target Alignment Model

## Overview

This example defines a predictive alignment model.

It estimates an output position based on current target position and optional velocity inputs.

The model is not tied to a specific application.

## Behavior

- uses position inputs as required signals
- uses velocity inputs if available
- predicts adjusted alignment output

## Degraded Operation

If velocity inputs are missing:

- behavior falls back to position-only estimation
- prediction quality may be reduced

## Files

- model.mdp.json contains the model definition
- reference_runtime.cpp provides a simple implementation example
