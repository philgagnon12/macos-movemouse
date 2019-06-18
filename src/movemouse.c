#include <CoreGraphics/CoreGraphics.h>

#include <stdlib.h>
#include <stdio.h>

CGError
moveMouseToDisplay
    (
        CGDirectDisplayID displayId
    )
{
    CGError           retVal        = 0;
    size_t            height        = 0;
    size_t            width         = 0;
    CGPoint           point         = {};

    width =  CGDisplayPixelsWide( displayId );
    height = CGDisplayPixelsHigh( displayId );

    point.x = width / 2;
    point.y = height / 2;

    retVal = CGDisplayMoveCursorToPoint(displayId, point);
    return retVal;
}

int main(int argc, char* argv[])
{
    CGError           retVal               = 0;
    CGDirectDisplayID activeDisplays[MOVEMOUSE_MAX_DISPLAYS];
    uint32_t          displayCount         = 0;
    uint32_t          displayIndex         = 0;
    CGDirectDisplayID displayIdToMouseMove = 0;

    if( 1 < argc )
    {
        displayIdToMouseMove = strtoul( argv[1], NULL, 10);
    }

    retVal = CGGetActiveDisplayList(MOVEMOUSE_MAX_DISPLAYS, activeDisplays, &displayCount);

    if( kCGErrorSuccess != retVal )
    {
        fprintf( stderr, "%s: %s: CGGetActiveDisplayList failed!\n", __FILE__, __FUNCTION__ );
    }
    else
    {
        for( displayIndex = 0; displayIndex < displayCount; displayIndex++ )
        {
            if( displayIdToMouseMove == activeDisplays[displayIndex] )
            {
                retVal = moveMouseToDisplay( displayIdToMouseMove );
            }
            else
            {
                printf("%d\n", activeDisplays[displayIndex]);
            }
        }
    }

    return retVal;
}
