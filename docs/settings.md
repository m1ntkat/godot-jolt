# Settings

This document details the project settings exposed by this extension as well as which of the
default project settings are relevant.

⚠️ Make sure you enable "Advanced Settings" in the top-right corner of the project settings window
in order to see the settings listed here.

## Table of Contents

- [Common](#common)
- [3D](#3d)
- [Jolt 3D](#jolt-3d)

## Common

These settings are part of Godot's default project settings and can be found under "Physics" -
"Common".

<table>
  <thead>
    <tr>
      <th>Category</th>
      <th>Name</th>
      <th>Supported</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>-</td>
      <td>Physics Ticks per Second</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Max Physics Steps per Frame</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Enable Object Picking</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
  </tbody>
</table>

## 3D

These settings are part of Godot's default project settings and can be found under "Physics" - "3D".

<table>
  <thead>
    <tr>
      <th>Category</th>
      <th>Name</th>
      <th>Supported</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>-</td>
      <td>Run on Separate Thread</td>
      <td>No</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Physics Engine</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Default Gravity</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Default Gravity Vector</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Default Linear Damp</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Default Angular Damp</td>
      <td>Yes</td>
      <td>-</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Sleep Threshold Linear</td>
      <td>No</td>
      <td>See extension settings <a href="#jolt-3d">below</a>.</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Sleep Threshold Angular</td>
      <td>No</td>
      <td>See extension settings <a href="#jolt-3d">below</a>.</td>
    </tr>
    <tr>
      <td>-</td>
      <td>Time Before Sleep</td>
      <td>No</td>
      <td>See extension settings <a href="#jolt-3d">below</a>.</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Solver Iterations</td>
      <td>No</td>
      <td>See extension settings <a href="#jolt-3d">below</a>.</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Contact Recycle Radius</td>
      <td>No</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Contact Max Separation</td>
      <td>No</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Contact Max Allowed Penetration</td>
      <td>No</td>
      <td>See extension settings <a href="#jolt-3d">below</a>.</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Default Contact Bias</td>
      <td>No</td>
      <td>-</td>
    </tr>
  </tbody>
</table>

## Jolt 3D

These settings are exposed by Godot Jolt and can be found under "Physics" - "Jolt 3D".

<table>
  <thead>
    <tr>
      <th>Category</th>
      <th>Name</th>
      <th>Description</th>
      <th>Notes</th>
    <tr>
  </thead>
  <tbody>
    <tr>
      <td>Sleep</td>
      <td>Enabled</td>
      <td>
        Whether bodies are allowed to go to sleep.
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Sleep</td>
      <td>Velocity Threshold</td>
      <td>
        The point velocity on a body's bounding box below which a body can be considered sleeping.
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Sleep</td>
      <td>Time Threshold</td>
      <td>
        Time spent below the velocity threshold after which a body can be considered sleeping.
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Kinematic</td>
      <td>Recovery Iterations</td>
      <td>
        The number of iterations to run when resolving penetration during things like
        <code>move_and_slide</code>.
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Kinematic</td>
      <td>Recovery Speed</td>
      <td>
        How much of the penetration to resolve per iteration during things like
        <code>move_and_slide</code>.
        <br><i>(0.0 = 0%, 1.0 = 100%)</i>
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Velocity Iterations</td>
      <td>The number of solver velocity iterations to run during a physics tick.</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Position Iterations</td>
      <td>The number of solver position iterations to run during a physics tick.</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Stabilization Factor</td>
      <td>
        How much of the position error to resolve during a physics tick.
        <br><i>(0.0 = 0%, 1.0 = 100%)</i>
      </td>
      <td>-</td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Contact Speculative Distance</td>
      <td>
        Radius around objects, inside which speculative contact points will be detected.
      </td>
      <td>
        Setting this too high will result in ghost collisions, as speculative contacts are based on
        the closest points during the collision detection step which may not be the actual closest
        points by the time the two objects hit.
      </td>
    </tr>
    <tr>
      <td>Solver</td>
      <td>Contact Allowed Penetration</td>
      <td>How much bodies are allowed to penetrate eachother.</td>
      <td>-</td>
    </tr>
    <tr>
      <td>Simulation</td>
      <td>More Deterministic</td>
      <td>Whether to make the simulation more deterministic.</td>
      <td>
        ⚠️ While this makes Jolt itself deterministic when using the same binary, this extension
        (or Godot itself) might not be. This setting should not be relied upon if determinism is a
        requirement.
      </td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Linear Velocity</td>
      <td>The maximum linear velocity that a body can reach.</td>
      <td>Meant to prevent the simulation from exploding if something goes wrong.</td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Angular Velocity</td>
      <td>The maximum angular velocity that a body can reach.</td>
      <td>Meant to prevent the simulation from exploding if something goes wrong.</td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Bodies</td>
      <td>The maximum number of bodies to support, awake or otherwise.</td>
      <td>
        When this limit is exceeded a warning is emitted and anything past that point is undefined
        behavior.
        <br><br>⚠️ This also applies within the editor.
      </td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Body Pairs</td>
      <td>The maximum number of body pairs to allow processing of.</td>
      <td>
        When this limit is exceeded a warning is emitted and any additional body pairs will be
        ignored.
      </td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Contact Constraints</td>
      <td>The maximum number of contact constraints to allow processing of.</td>
      <td>
        When this limit is exceeded a warning is emitted and any additional contacts will be
        ignored.
      </td>
    </tr>
    <tr>
      <td>Limits</td>
      <td>Max Temporary Memory</td>
      <td>
        The amount of memory to pre-allocate for the stack-allocator used within a physics tick.
      </td>
      <td>
        When this limit is exceeded a warning is emitted and any additional allocations will fall
        back to a much slower general-purpose allocator.
      </td>
    </tr>
  </tbody>
</table>
