#ifndef CANDLELIGHTENGINE_DATALOADER_H
#define CANDLELIGHTENGINE_DATALOADER_H

#include <map>
#include <string>
#include "structures/Texture.h"

/*====================================
 * Data Loader
 * -----------------------------------
 * Mainly used for texture and sound
 * loading.
 *
 * Each resource is assigned an ID
 */

namespace Core_NS {

    class DataLoader {
    private:
        static std::map<std::string, Texture*> _loadedTextures;

    public:
        static unsigned char *get_texture2d(std::string textureName);
        static void load_texture2ds(const char *texturesDirectory);
    };

} // Core_NS

#endif //CANDLELIGHTENGINE_DATALOADER_H
