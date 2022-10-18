#include "app.h"



/**********************
 *  STATIC VARIABLES
 **********************/
static lv_style_t textRobotoStyle;
static lv_style_t buttonPressedStyle;
static lv_style_t textRoboto24GreenStyle;
static lv_style_t textRobotoGreenStyle;
static lv_style_t whiteBackground;
lv_style_t greenPressedStyle;
const int zoomFactor = 90; // fattore di zoom per le immagini: 256 è senza zoom, >256= immagine più grande, <256 inmmagine più piccola

lv_obj_t* resetLabel;
lv_obj_t* tileView;
lv_obj_t* mainScreen;
lv_obj_t* widgetScreen;

/* Risorse in file .c*/
extern lv_font_t roboto_14;
extern lv_font_t roboto_24;
extern lv_img_dsc_t resetbtn;
extern lv_img_dsc_t conteinerDati;
extern lv_img_dsc_t topSelectionButtonImg;
extern lv_img_dsc_t BottomLeftSelectionButtonImg;
extern lv_img_dsc_t BottomMidSelectionButtonImg;
extern lv_img_dsc_t BottomRightSelectionButtonImg;
extern lv_img_dsc_t topMidSelectionButtonImg;


/**********************
 *       FUNCTIONS
 **********************/

void reset_cb(lv_event_t* e) {
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED) {
        resetInitialChecked();
    }
}

static bool widgetMenuAttivo = false;
void tileSwipe_cb(lv_event_t* e) {
    lv_obj_t* target = lv_event_get_target(e);
    lv_obj_t* tile = lv_tileview_get_tile_act(target);
    if (tile == widgetScreen && !widgetMenuAttivo) {
        menuLoading(widgetScreen);
        widgetMenuAttivo = true;
    }
    else if(tile == mainScreen && widgetMenuAttivo){
        menuHiding();

        widgetMenuAttivo = false;
    }
}

void app_create()
{
    
    tileView     = lv_tileview_create(NULL);
    mainScreen   = lv_tileview_add_tile(tileView, 0, 0, LV_DIR_RIGHT);
    widgetScreen = lv_tileview_add_tile(tileView, 1, 0, LV_DIR_LEFT);


    lv_obj_set_size(mainScreen, 1280, 800);   
    lv_obj_clear_flag(mainScreen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_size(widgetScreen, 1280, 800);
    lv_obj_clear_flag(widgetScreen, LV_OBJ_FLAG_SCROLLABLE);

    widgetInit(widgetScreen);
    lv_obj_add_event_cb(tileView, tileSwipe_cb, LV_EVENT_VALUE_CHANGED, NULL);



    lv_style_init(&whiteBackground);
    lv_style_set_bg_color(&whiteBackground, lv_color_white());
    lv_style_set_border_color(&whiteBackground, lv_color_white());
    lv_style_init(&textRoboto24GreenStyle);
    lv_style_set_text_font(&textRoboto24GreenStyle, &roboto_24);
    lv_style_set_text_color(&textRoboto24GreenStyle, colorGreen);
     /*
     * Inizializzo bocca
     */
    lv_obj_t * teethContainer = lv_obj_create(mainScreen);

    lv_obj_align(teethContainer, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(teethContainer, lv_pct(95), lv_pct(90));
    lv_obj_clear_flag(teethContainer, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(teethContainer, &whiteBackground, LV_STATE_DEFAULT);

    lv_obj_t * rightLabel = lv_label_create(teethContainer);
    lv_obj_set_align(rightLabel, LV_ALIGN_LEFT_MID);
    lv_label_set_text(rightLabel, "R");
    lv_obj_add_style(rightLabel, &textRoboto24GreenStyle, LV_STATE_DEFAULT);



    
}


//void app_init_screen() {
    //lv_disp_t* dispp = lv_disp_get_default();
    //lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),false, LV_FONT_DEFAULT);
    //lv_disp_set_theme(dispp, theme);


    //app_create();
    //lv_disp_load_scr(tileView);
//}
