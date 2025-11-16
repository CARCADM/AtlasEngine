# Atlas Engine Development Logs

This is going to be used to keep track of Atlas Engine's development.

## Timeline

### Prior to 11/15/2025

- CMake subdirectories implementation.
- SDL window creation is now working.
- Subsystems arcitecture started.

### 10/15/2025

- Initialized the Github repository.
- Added some enriched text with a readme.md.

### 10/16/2025

- Added a bunch of new subsystems, Util and Renderer
- Began implementation of the ECS.

#### Issues with ECS implementation

I had some pretty big issues with the implementation of the ECS. I started
with issues when I was creating the childComponent array, which was originally
an ```std::unordered_set```, but because I tried to store the type Component, it had
no hash or equal_to definition. Implementing both of those is too much for 
such a simple class, so instead I switched things up and made the array an 
```std::unordered_map```, while storing a component behind it. This made things 
just a little bit easier for me to work with as the key was now of type 
enum, which did have proper hash map definitions.