#include "TravelManager.h"
#include "TravelManagerFrame.h"

IMPLEMENT_APP(TravelManager)

bool TravelManager::OnInit()
{
    TravelManagerFrame *app = new TravelManagerFrame(wxT("Thanh"));
    app->Show(true);
    return true;
}