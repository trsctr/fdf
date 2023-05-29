int    set_color(int transparency, int red, int green, int blue)
{
    return (transparency << 24 | red << 16 | green << 8 | blue);
}

int    get_t(int color)
{
    return ((color >> 24) & 0xFF);
}

int    get_r(int color)
{
    return ((color >> 16) & 0xFF);
}

int    get_g(int color)
{
    return ((color >> 8) & 0xFF);
}

int    get_b(int color)
{
    return (color & 0xFF);
}

// void	test()
// {
// 	int color;
// 	int r;
// 	int g;
// 	int b;

// 	color = 0xFF11AA00;
// 	r = get_r(color);
// 	g = get_g(color);
// 	b = get_b(color);
// 	b++;
// 	set_color(0, r, g, b);

// }