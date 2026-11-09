# Tiltrotor Flight Simulation and Analysis

An open-source C++17 six-degree-of-freedom flight-dynamics engine for tiltrotor aircraft, designed and validated using public data from the Bell XV-15 tiltrotor aircraft.

Status: in development. v0.1.0 in progress.

![CI](https://github.com/ishaansharma2903/tiltrotor-flight-dynamics/actions/workflows/ci.yml/badge.svg)

## Quickstart

```bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug
```

## Planned scope (v0.1.0)

- Verified rigid-body core with quaternion attitude
- Rotor, nacelle tilt and airframe components
- Hover trim and linearization
- Hover trim validated against published XV-15 data

## Repository layout

`include/` public headers, `src/` implementation, `apps/` command-line tools, `tests/` unit tests, `docs/` notes.

## License

MIT. See `LICENSES/MIT.txt`.
