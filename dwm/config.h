/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 1;   /* horiz inner gap between windows */
static const unsigned int gappiv = 1;   /* vert inner gap between windows */
static const unsigned int gappoh = 1;   /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 1;   /* vert outer gap between windows and screen edge */
static const int smartgaps_fact = 1;    /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[] = "autostart_blocking.sh";
static const char autostartsh[] = "autostart.sh";
static const char dwmdir[] = "dwm";
static const char localshare[] = ".local/share";
static const int showbar = 1;                 /* 0 means no bar */
static const int topbar = 1;                  /* 0 means bottom bar */
static const int bar_height = 30;             /* 0 means derive from font, >= 1 explicit height */
static const int vertpad = 0;                 /* vertical padding of bar */
static const int sidepad = 0;                 /* horizontal padding of bar */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int showsystray = 1;             /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype = INDICATOR_BOTTOM_BAR;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static const char* fonts[] = {
  "JetBrainsMono Nerd Font:size=11.5:style=bold:antialias=true:autohint=true",
  "NotoEmoji Nerd Font:size=11.5:antialias=true:autohint=true",
  "FandolHei:size=11.5:style=bold:antialias=true:autohint=true",
  "Font Awesome 5 Free:size=20:style=bold:antialias=true:autohint=true",
  "Material Design Icons"
};
static const char dmenufont[] = "JetBrainsMono Nerd Font:size=10:style=bold:antialias=true:autohint=true";

/* Colorscheme */
#include "themes/tokyonight.h"

static char* colors[][ColCount] = {
  /*                   fg                bg                border           float     */
  [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor, normfloatcolor },
  [SchemeSel] = { selfgcolor, selbgcolor, selbordercolor, selfloatcolor },
  [SchemeTitleNorm] = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
  [SchemeTitleSel] = { titleselfgcolor, titleselbgcolor, titleselbordercolor, titleselfloatcolor },
  [SchemeTagsNorm] = { tagsnormfgcolor, tagsnormbgcolor, tagsnormbordercolor, tagsnormfloatcolor },
  [SchemeTagsSel] = { tagsselfgcolor, tagsselbgcolor, tagsselbordercolor, tagsselfloatcolor },
  [SchemeHidNorm] = { hidnormfgcolor, hidnormbgcolor, c000000, c000000 },
  [SchemeHidSel] = { hidselfgcolor, hidselbgcolor, c000000, c000000 },
  [SchemeUrg] = { urgfgcolor, urgbgcolor, urgbordercolor, urgfloatcolor },

};

const char* spcmd1[] = { "st", "-n", "spterm", "-g", "156x42", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  { "spterm", spcmd1 },

};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by
 * changing the number of strings in the tags array. This build does things a
 * bit different which has some added benefits. If you need to change the number
 * of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *                         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7",
 * "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" }, *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1
 * through 9, while the tags for the second monitor would be named A through I.
 * A third monitor would start again at 1 through 9 while the tags on a fourth
 * monitor would also be named A through I. Note the tags count of NUMTAGS*2 in
 * the array initialiser which defines how many tag text / icon exists in the
 * array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both
 * cases work the same from a technical standpoint - the icon index is derived
 * from the tag index and the monitor index. If the icon index is is greater
 * than the number of tag icons then it will wrap around until it an icon
 * matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration
 * patches.
 */
static char* tagicons[][NUMTAGS] = {
  [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
  [ALTERNATIVE_TAGS] = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
  [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields
 * depending on the patches you enable.
 */
static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   *	WM_WINDOW_ROLE(STRING) = role
   *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
   */
  RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
      RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
          RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
              RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
                  RULE(.title = "About Mozilla Firefox", .isfloating = 1)
                      RULE(.class = "Glimpse", .isfloating = 1)
                          RULE(.title = "IWarp", .isfloating = 1, .iscentered = 1)
                              RULE(.class = "Pavucontrol", .isfloating = 1, .iscentered = 1)
                                  RULE(.class = "Gimp", .isfloating = 1)
                                      RULE(.class = "gimp", .isfloating = 1)
                                          RULE(.class = "Gimp.bin", .isfloating = 1)
                                              RULE(.class = "gimp.bin", .isfloating = 1)
                                                  RULE(.class = "Gcolor2", .isfloating = 1, .iscentered = 1)
                                                      RULE(.class = "Gcolor3", .isfloating = 1, .iscentered = 1)
                                                          RULE(.class = "gnome-calculator", .isfloating = 1)
                                                              RULE(.class = "Gnome-calculator", .isfloating = 1)
                                                                  RULE(.class = "Lxappearance", .isfloating = 1, .iscentered = 1)
                                                                      RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
                                                                          RULE(.instance = "spfm", .tags = SPTAG(1), .isfloating = 1)

};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for
 * active?) bar - bar index, 0 is default, 1 is extrabar alignment - how the
 * module is aligned compared to other modules widthfunc, drawfunc, clickfunc -
 * providing bar module width, draw and click functions name - does nothing,
 * intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
  /* monitor  bar    alignment         widthfunc          drawfunc clickfunc
   * name
   */
  { -1, 0, BAR_ALIGN_LEFT, width_tags, draw_tags, click_tags, "tags" },
  { 0, 0, BAR_ALIGN_RIGHT, width_systray, draw_systray, click_systray, "systray" },
  { -1, 0, BAR_ALIGN_LEFT, width_ltsymbol, draw_ltsymbol, click_ltsymbol, "layout" },
  { 0, 0, BAR_ALIGN_RIGHT, width_pwrl_status, draw_pwrl_status, click_pwrl_status, "powerline_status" },
  { -1, 0, BAR_ALIGN_NONE, width_wintitle, draw_wintitle, click_wintitle, "wintitle" },
  /* if you want a titlebar like the awesomewm comment the "wintitle" and
     uncomment the "awesomebar" */
  //{ -1,       0,     BAR_ALIGN_NONE,   width_awesomebar, draw_awesomebar,
  // click_awesomebar, "awesomebar" },
};

/* layout(s) */
static const float mfact = 0.50;  /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;     /* number of clients in master area */
static const int resizehints = 0; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=", tile }, /* first entry is default */
  { "|M|", centeredmaster },
  { "(@)", spiral },
  { "[M]", monocle },
  { "><>", NULL }, /* no layout function means floating behavior */
  { NULL, NULL },
  /* { "HHH",      grid },
     { "|||",      col },
     { "TTT",      bstack },
     { "===",      bstackhoriz },
     { "[D]",      deck },
     { ">M>",      centeredfloatingmaster },*/
};

/* key definitions */
#define PrintScreenDWM 0x0000ff61
#define M Mod4Mask
#define A Mod1Mask
#define S ShiftMask
#define C ControlMask
#define TAGKEYS(KEY, TAG)                             \
  { M, KEY, view, { .ui = 1 << TAG } },               \
      { M | C, KEY, toggleview, { .ui = 1 << TAG } }, \
      { M | S, KEY, tag, { .ui = 1 << TAG } },        \
      { M | C | S, KEY, toggletag, { .ui = 1 << TAG } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                      \
  {                                                     \
    .v = (const char*[]) { "/bin/sh", "-c", cmd, NULL } \
  }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char* dmenucmd[] = { "dmenu_run", "-sb", "#c574dd", "-sf",
  "#1a1b26", "-p", "Run: ", NULL };
static const char* qutebrowser[] = { "qutebrowser", NULL };
static const char* dmenucmd2[] = { "rofi", "-show", "drun", NULL };
static const char* termcmd[] = { "st", NULL };
#include <X11/XF86keysym.h>

static Key keys[] = {
  /* modifier         key            function argument */
  { M, XK_z, hidewin, { 0 } },
  { M | S, XK_z, restorewin, { 0 } },
  { A, XK_z, hideotherwins, { 0 } },
  { A | S, XK_z, restoreotherwins, { 0 } },
  { A, XK_o, spawn, { .v = dmenucmd } },
  { M, XK_o, spawn, { .v = dmenucmd2 } },
  { M, XK_Return, spawn, { .v = termcmd } },
  // 打开浏览器
  { M, XK_b, spawn, { .v = qutebrowser } },
  // 临时窗口
  { A, XK_t, togglescratch, { .ui = 0 } },
  // 窗口缩放
  { M | A, XK_u, incrgaps, { .i = +1 } },
  { M | A | S, XK_u, incrgaps, { .i = -1 } },
  // 窗口间距
  { M | A, XK_i, incrigaps, { .i = +1 } },
  { M | A | S, XK_i, incrigaps, { .i = -1 } },
  // 整体缩放
  { M | A, XK_o, incrogaps, { .i = +1 } },
  { M | A | S, XK_o, incrogaps, { .i = -1 } },

  // 全屏
  { M | S, XK_f, togglefullscreen, { 0 } },
  // 隐藏状态栏
  { M | S, XK_b, togglebar, { 0 } },

  // 移动窗口
  { M | S, XK_j, movestack, { .i = +1 } },
  { M | S, XK_k, movestack, { .i = -1 } },

  { M, XK_j, focusstack, { .i = +1 } },
  { M, XK_k, focusstack, { .i = -1 } },

  // 左右栈加减
  { M | S, XK_d, incnmaster, { .i = +1 } },
  { M, XK_d, incnmaster, { .i = -1 } },

  // 调整窗口宽度
  { M | S, XK_h, setmfact, { .f = -0.01 } },
  { M | S, XK_l, setmfact, { .f = +0.01 } },

  // 主窗口
  { M | S, XK_Return, zoom, { 0 } },
  // 切换工作窗口
  { A, XK_Tab, view, { 0 } },
  // 杀死当前窗口
  { M | S, XK_q, killclient, { 0 } },
  // 切换窗口排列方式
  { M, XK_Tab, cyclelayout, { .i = -1 } },
  { M | S, XK_Tab, cyclelayout, { .i = +1 } },

  // 专注显示
  { M, XK_a, togglefloating, { 0 } },
  // 全部窗口
  { M, XK_0, view, { .ui = ~0 } },
  { M | S, XK_0, tag, { .ui = ~0 } },
  { M, XK_comma, focusmon, { .i = -1 } },
  { M, XK_period, focusmon, { .i = +1 } },
  { M | S, XK_comma, tagmon, { .i = -1 } },
  { M | S, XK_period, tagmon, { .i = +1 } },
  TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
      TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
          TAGKEYS(XK_9, 8) { M | S, XK_c, quit, { 0 } },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click      event mask    button   function        argument */
  { ClkLtSymbol, 0, Button1, setlayout, { 0 } },
  { ClkLtSymbol, 0, Button3, setlayout, { .v = &layouts[2] } },
  { ClkWinTitle, 0, Button1, togglewin, { 0 } },
  { ClkWinTitle, 0, Button3, showhideclient, { 0 } },
  { ClkWinTitle, 0, Button2, zoom, { 0 } },
  { ClkStatusText, 0, Button2, spawn, { .v = termcmd } },
  { ClkClientWin, M, Button1, movemouse, { 0 } },
  { ClkClientWin, M, Button2, togglefloating, { 0 } },
  { ClkClientWin, M, Button3, resizemouse, { 0 } },
  { ClkClientWin, M | S, Button1, dragmfact, { 0 } },
  { ClkTagBar, 0, Button1, view, { 0 } },
  { ClkTagBar, 0, Button3, toggleview, { 0 } },
  { ClkTagBar, M, Button1, tag, { 0 } },
  { ClkTagBar, M, Button3, toggletag, { 0 } },
};
