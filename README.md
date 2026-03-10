# UnrealShooterGame (linux-clean)
Third-person shooter prototype in Unreal Engine 5.7 with C++ gameplay systems, Blueprint integration, and FMOD-driven audio behaviors.

## Demo

[![Gameplay Audio Systems Demo](https://img.youtube.com/vi/z8qaRSRHF6U/0.jpg)](https://youtu.be/z8qaRSRHF6U)

Gameplay-driven audio systems including surface-based footsteps, weapon audio, and a dynamic low-health heartbeat + music ducking system implemented using Unreal Engine 5.7, C++, Blueprint, and FMOD.

## Branch Context
- `linux-clean` (this branch): FMOD-integrated gameplay/audio version.
- `main`: C++ baseline version without FMOD-focused branch additions.
- Baseline branch link: https://github.com/DanImbert/UnrealShooterGame/tree/main

## Highlights
- C++ player combat, damage handling, and game flow logic.
- Low-health trigger path in C++ (`OnLowHealthTriggered`) for Blueprint/FMOD reaction hooks.
- AI behavior setup using Behavior Trees + Blackboard.
- Enhanced Input + character animation/locomotion pipeline.
- HUD/widgets for gameplay feedback.

## Tech Stack
- Unreal Engine 5.7
- C++ + Blueprint
- FMOD Studio integration
- Unreal Behavior Trees / Blackboard
- Git + GitHub

## Run Notes
1. Open `DanUnrealShooter.uproject` in UE 5.7.
2. Generate project files and build `DanUnrealShooter` target.
3. Launch from Unreal Editor.

## Portfolio Notes
- This branch is curated to show implementation quality and feature integration choices.
- Large generated/binary audio assets may be excluded or referenced externally due to Git LFS budget limits.
- If audio banks are missing locally, gameplay systems still demonstrate C++/Blueprint architecture and feature flow.
