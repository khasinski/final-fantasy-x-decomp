/* Start a character effect state and record its duration. */
typedef struct CharacterEffect {
    int character;
    void *handle;
    int state;
    int duration;
    int frame;
} CharacterEffect;
extern int func_001CE050(int character, int state);

void func_01B007D8(CharacterEffect *effect, int state)
{
    if (effect->character != 255) {
        effect->frame = 0;
        effect->state = state;
        effect->duration = func_001CE050(effect->character, state);
    }
}
