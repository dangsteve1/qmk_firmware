# dangsteve1's GMMK Pro layout

I started off using andrebrait's keymap and adjusted it to a mac keyboard and my liking.
It basically reflects my needs for primarily using it on a Mac, using both Delete/Eject, and using the function row as media keys, as well as a full Home/PgUp/PgDwn/End column.

The differences are as follows:

-   Dedicated MacOS and Windows/Linux layers
    -   Switching between them by pressing Fn + CAPS LOCK
-   Disabled Mouse Keys (to fix issues with KVM switches and also because they're not used here anyway)
-   Short DEBOUNCE time (5 ms)
-   Per-key debounce algorithm (sym_defer_pk)
-   RGB turns off after 1 minutes of inactivity
-   RGB turns off when USB is suspended
-   Layer 0:
    -   Print Screen (default) -> Delete
    -   Delete (default) -> Home
    -   Function row mirrors the mac keyboards
    -   Swap windows and alt keys for option and command keys
    -   Depressed encoder button is play/pause
-   Layer 1 (accessed by pressing Fn):
    -   Fn + Delete -> Eject
    -   Fn + Home -> Print Screen
    -   Fn + encoder rotation adjust brightness
-   Layer 2 (accessed by pressing Fn):
-   Fn + encoder rotation changes rgb pattern
-   Layer 3 (accessed by pressing Fn):
-   Fn + encoder rotation triggers page up & page down

This keymap also includes CAPS LOCK ON indicator.\
All left and right side LEDs, and the Caps key LED will turn solid red while CAPS LOCK is ON.

No other changes have been made. \
The other keys on each layer have been kept intact.
