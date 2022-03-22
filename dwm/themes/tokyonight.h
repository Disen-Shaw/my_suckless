static char c000000[]                    = "#c574dd"; // placeholder value

static char normfgcolor[]                = "#a9b1d6";
static char normbgcolor[]                = "#1a1b26";
static char normbordercolor[]            = "#2b2f40";
static char normfloatcolor[]             = "#1a1b26";

static char selfgcolor[]                 = "#a9b1d6";
static char selbgcolor[]                 = "#c574dd";
static char selbordercolor[]             = "#c574dd";
static char selfloatcolor[]              = "#c574dd";

static char titlenormfgcolor[]           = "#a9b1d6";
static char titlenormbgcolor[]           = "#1a1b26";
static char titlenormbordercolor[]       = "#2b2f40";
static char titlenormfloatcolor[]        = "#1a1b26";

static char titleselfgcolor[]            = "#9ECE6A";
static char titleselbgcolor[]            = "#1a1b26";
static char titleselbordercolor[]        = "#1a1b26";
static char titleselfloatcolor[]         = "#9a7ecc";

static char tagsnormfgcolor[]            = "#a9b1d6";
static char tagsnormbgcolor[]            = "#1a1b26";
static char tagsnormbordercolor[]        = "#2b2f40";
static char tagsnormfloatcolor[]         = "#1a1b26";

static char tagsselfgcolor[]             = "#c574dd";
static char tagsselbgcolor[]             = "#21232a";
static char tagsselbordercolor[]         = "#c574dd";
static char tagsselfloatcolor[]          = "#c574dd";

static char hidnormfgcolor[]             = "#e06c75";
static char hidselfgcolor[]              = "#c574dd";
static char hidnormbgcolor[]             = "#1a1b26";
static char hidselbgcolor[]              = "#1a1b26";

static char urgfgcolor[]                 = "#a9b1d6";
static char urgbgcolor[]                 = "#1a1b26";
static char urgbordercolor[]             = "#4ABAAF";
static char urgfloatcolor[]              = "#1a1b26";

static char *statuscolors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { "#F7768E",        normbordercolor,  normbordercolor,      normfloatcolor },
	[SchemeSel]          = { "#7AA2F7",        normbgcolor,      selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { "#39D7E5",        normbordercolor,  titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { "#4ABAAF",        normbgcolor,      titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { "#E0AF68",        normbordercolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { "#C574DD",        normbgcolor,      tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { "#7dcfff",        normbordercolor,  c000000,              c000000 },
	[SchemeHidSel]       = { "#9ec07c",        normbgcolor,      c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};