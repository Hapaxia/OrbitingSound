# Orbiting Sound

## Description
Animates the position of a looping monophonic sound so that it orbits the listener.

## Speaker Set-up
On a stereo audio system, the effect heard will be a simple but smooth "ping-pong" between the two speakers.

However, on a surround sound audio system, the effect heard will be that the sound orbits your position, starting from in front of you, passes you on the right, continues behind you and then passes you on the left. This circling continues indefinitely until you press the Escape key or close the window.

## Interactive Visualisation
If the `#define SHOW_INTERACTIVE_VISUALISATION` line is commented out, Orbiting Sound will only create the circling audio (does not include the Interative Visualisation).

If the `#define SHOW_INTERACTIVE_VISUALISATION` line is _not_ commented out, Orbiting Sound will include a graphical window that shows a simple visual representation of the position of the listener and the sound.

The Interactive Visualisation also responds to a couple of controls:
- [SPACE]  
Changes direction of the orbit
- [+] (number pad)  
Increases speed of the orbit
- [-] (number pad)  
Decreases speed of the orbit

## Note
Requires C++ and [SFML] version 2

[SFML]: http://sfml-dev.org
