# Generic Anomaly Monitor

## Overview

This example defines a generic anomaly detection model.

It evaluates one or more input signals against expected behavior and produces an anomaly score and anomaly flag.

The model is application-neutral and may be used in monitoring, diagnostics, condition tracking, or other systems through external runtime binding.

## Behavior

- accepts continuous input signals
- evaluates deviation from expected behavior
- produces a score and flag output

## Degraded Operation

If optional context inputs are missing:

- the model continues using core monitored signals
- anomaly confidence or selectivity may be reduced

## Files

- model.mdp.json contains the model definition
- reference_runtime.cpp provides a simple implementation example
