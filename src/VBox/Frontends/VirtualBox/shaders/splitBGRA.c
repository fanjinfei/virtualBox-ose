/* $Id: splitBGRA.c 55401 2015-04-23 10:03:17Z vboxsync $ */
float vboxSplitBGRA(vec4 color, float coord)
{
    int pix = int(coord);
    float part = coord - float(pix);
    if(part < 0.25)
        return color.b;
    if(part < 0.5)
        return color.g;
    if(part < 0.75)
        return color.r;
    return color.a;
}
