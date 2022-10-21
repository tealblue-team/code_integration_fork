#include "../../lvgl.h"
#include "selectButtons.h"

void dentalArcInit(lv_obj_t *parent);



/* Callback functions*/
void reset_all_dentalArc();
void topSelectionChecked(lv_event_t * e);
void select_central_part(lv_event_t * e); // selected central part
void bottomLeftSelectionChecked(lv_event_t* e);
void bottomRightSelectionChecked(lv_event_t* e);
void bottomMidSelectionChecked(lv_event_t* e);
void topMidSelectionChecked(lv_event_t* e);
