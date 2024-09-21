
#include "store.h"
#include "store_ui.h"

using namespace std;

int main() {
    const Store store;
    StoreUi storeUi(store);
    storeUi.menu();

    return 0;
}
