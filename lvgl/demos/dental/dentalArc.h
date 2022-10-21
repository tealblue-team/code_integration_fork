﻿#include "../../lvgl.h"
#include "selectButtons.h"

void dentalArcInit(lv_obj_t *parent);



/* Callback functions*/
void resetInitialChecked_central_button();
void resetInitialChecked_all();
void topSelectionChecked(lv_event_t * e);
void bottomLeftSelectionChecked(lv_event_t* e);
void bottomRightSelectionChecked(lv_event_t* e);
void bottomMidSelectionChecked(lv_event_t* e);
void topMidSelectionChecked(lv_event_t* e);
