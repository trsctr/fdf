#include "libft.h"
#include <stdio.h>

static void red ()
{
  printf("\033[1;31m");
}

static void bold ()
{
	printf("\033[1m");
}

static void green ()
{
  printf("\033[1;32m");
}

static void regular ()
{
  printf("\033[0m");
}

static void checkresult (int ret1, int ret2)
{
	char *success = "\nSUCCESS! Return values match!\n\n";
	char *fail = "\nFAIL! Return values don't match.\n\n";
	
	if (ret1 == ret2)
	{
		green();
		printf("%s", success);
		regular();
	}
	else if (ret1 != ret2)
	{
		red();
		printf("%s", fail);
		regular();
	}

}

int main (void)
{
	int ret1;
	int ret2;
	int i = INT_MAX;
	unsigned int uneg = -51;
	unsigned int u = UINT_MAX;
	unsigned int hextest = 3820061864;
	char *teststring = "testing testing";
	char *out1 = "::::: custom ft_printf:\n";
	char *out2 = "::::: libc printf:\n";
	

	bold();
	printf("MY FIRST FT_PRINTF TESTER\n\n");
	printf("############################\n");
	printf("# SINGLE FORMAT SPECIFIERS #\n");
	printf("############################\n\n");
	regular();

	// %%
	bold(); printf("%%%% - PERCENT SIGN\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%%");
	printf("\n%s", out2);
	ret2 = printf("%%");
	checkresult(ret1, ret2);

	// %c
	bold(); printf("%%c - SINGLE CHARACTER\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%c", '?');
	printf("\n%s", out2);
	ret2 = printf("%c", '?');
	checkresult(ret1, ret2);

	// %i
	bold(); printf("%%i - INTEGER IN BASE 10\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%i", i);
	printf("\n%s", out2);
	ret2 = printf("%i", i);
	checkresult(ret1, ret2);

	// %d
	bold(); printf("%%d - DECIMAL (BASE 10) NUMBER\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%d", i);
	printf("\n%s", out2);
	ret2 = printf("%d", i);
	checkresult(ret1, ret2);

	// %u
	bold(); printf("%%u - UNSIGNED DECIMAL (BASE 10) NUMBER (UINT_MAX)\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%u", u);
	printf("\n%s", out2);
	ret2 = printf("%u", u);
	checkresult(ret1, ret2);

	bold(); printf("%%u - UNSIGNED DECIMAL (BASE 10) NUMBER, BUT THE NUMBER IS -51\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%u", uneg);
	printf("\n%s", out2);
	ret2 = printf("%u", uneg);
	checkresult(ret1, ret2);

	bold(); printf("%%s - CHARACTER STRING\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%s", teststring);
	printf("\n%s", out2);
	ret2 = printf("%s", teststring);
	checkresult(ret1, ret2);

	bold(); printf("%%x - HEXADECIMAL NUMBER IN LOWERCASE FORMAT\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%x", hextest);
	printf("\n%s", out2);
	ret2 = printf("%x", hextest);
	checkresult(ret1, ret2);

	bold(); printf("%%X - HEXADECIMAL NUMBER IN UPPERCASE FORMAT\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%X", hextest);
	printf("\n%s", out2);
	ret2 = printf("%X", hextest);
	checkresult(ret1, ret2);

	bold(); printf("%%p - POINTER ADDRESS IN HEXADECIMAL FORMAT\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("%p", (void *)6316134613616316134);
	printf("\n%s", out2);
	ret2 = printf("%p", (void *)6316134613616316134);
	checkresult(ret1, ret2);

	bold();
	printf("##############################\n");
	printf("# MULTIPLE FORMAT SPECIFIERS #\n");
	printf("##############################\n\n");
	regular();

	bold(); printf("TEST 1 - character: %%c decimal: %%d string: %%s percent sign: %%\n"); regular();
	printf("%s", out1);
	ret1 = ft_printf("character: %c decimal: %d string: %s percent sign: %%", '!', i, teststring);
	printf("\n%s", out2);
	ret2 = printf("character: %c decimal: %d string: %s percent sign: %%", '!', i, teststring);
	checkresult(ret1, ret2);

	bold();
	printf("#####################\n");
	printf("# ERIKOIS TAPAUKSET #\n");
	printf("#####################\n\n");
	regular();

	printf("%% STRINGIN LOPUSSA\n");
	printf("%s", out1);
	char *s = "meneeko vituiks%";
	ret1 = ft_printf(s, "haha");
	printf("\n%s", out2);
	ret2 = printf(s);
	checkresult(ret1, ret2);

	ft_printf("%d\n", ret1);
	ft_printf("%d\n", ret2);
}