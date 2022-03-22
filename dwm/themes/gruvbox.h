static char c000000[]                    = "#bc7ad9"; // placeholder value

static char normfgcolor[]                = "#f9f5d7";
static char normbgcolor[]                = "#1d2021";
static char normbordercolor[]            = "#282828";
static char normfloatcolor[]             = "#1d2021";

static char selfgcolor[]                 = "#ffffff";
static char selbgcolor[]                 = "#076678";
static char selbordercolor[]             = "#076678";
static char selfloatcolor[]              = "#076678";

static char titlenormfgcolor[]           = "#f9f5d7";
static char titlenormbgcolor[]           = "#1d2021";
static char titlenormbordercolor[]       = "#282828";
static char titlenormfloatcolor[]        = "#1d2021";

static char titleselfgcolor[]            = "#b8bb26";
static char titleselbgcolor[]            = "#1d2021";
static char titleselbordercolor[]        = "#1d2021";
static char titleselfloatcolor[]         = "#076678";

static char tagsnormfgcolor[]            = "#f9f5d7";
static char tagsnormbgcolor[]            = "#1d2021";
static char tagsnormbordercolor[]        = "#282828";
static char tagsnormfloatcolor[]         = "#1d2021";

static char tagsselfgcolor[]             = "#83a598";
static char tagsselbgcolor[]             = "#282828";
static char tagsselbordercolor[]         = "#83a598";
static char tagsselfloatcolor[]          = "#83a598";

static char hidnormfgcolor[]             = "#fb4934";
static char hidselfgcolor[]              = "#83a598";
static char hidnormbgcolor[]             = "#1d2021";
static char hidselbgcolor[]              = "#1d2021";

static char urgfgcolor[]                 = "#f9f5d7";
static char urgbgcolor[]                 = "#1d2021";
static char urgbordercolor[]             = "#076678";
static char urgfloatcolor[]              = "#1d2021";

static char *statuscolors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { "#fb4934",      normbordercolor,    normbordercolor,      normfloatcolor },
	[SchemeSel]          = { "#fabd2f",      normbgcolor,	     selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { "#458588",      normbordercolor,    titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { "#427b58",      normbgcolor,	     titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { "#d79921",      normbordercolor,    tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { "#b16286",      normbgcolor,	     tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { "#83a598",      normbordercolor,    c000000,              c000000 },
	[SchemeHidSel]       = { "#9ec07c",      normbgcolor,	     c000000,              c000000 },
	[SchemeUrg]          = { "#076678",      normbordercolor,    urgbordercolor,       urgfloatcolor },
};
