#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

auto mod = Mod::get();

class $modify(Editor, LevelEditorLayer) {
    struct Fields {
        bool dontFade = mod->getSettingValue<bool>("dont-fade");
        bool dontEnter = mod->getSettingValue<bool>("dont-enter");
        bool noGlow = mod->getSettingValue<bool>("no-glow");
    };

    GameObject* createObject(int p0, CCPoint p1, bool p2) {
        auto obj = LevelEditorLayer::createObject(p0, p1, p2);
        auto fields = m_fields.self();
        obj->m_isDontFade = fields->dontFade;
        obj->m_isDontEnter = fields->dontEnter;
        obj->m_hasNoGlow = fields->noGlow;
        return obj;
    }
};