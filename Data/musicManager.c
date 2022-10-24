#include "include/musicManager.h"

struct audsrv_fmt_t musicFormat;

extern char* root;

void initMusicFormat()
{
	musicFormat.bits = 16;
	musicFormat.freq = 44100;
	musicFormat.channels = 1;
	
	SifInitRpc(0);

	
}



void LoadMusic(BGM *bgm)
{
	char* tempRoot = "host:";
	strncpy(tempRoot, root, strlen(root));
	
	//bgm->ret = SifLoadModule("rom0:LIBSD", 1, NULL);

	bgm->ret = SifLoadModule(strcat(tempRoot,"audsrv.irx"), 1, NULL);

	bgm->ret = audsrv_init();
	
	if (bgm->ret != 0)
	{
		printf("sample: failed to initialize audsrv\n");
		printf("audsrv returned error string: %s\n", audsrv_get_error_string());
		return 1;
	}

	
	bgm->err = audsrv_set_format(&musicFormat);
	audsrv_set_volume(MAX_VOLUME);

	bgm->wav = fopen(bgm->fileName, "rb");
	
	if (bgm->wav == NULL)
	{
		printf("failed to open wav file\n");
		audsrv_quit();
		return 1;
	}

	fseek(bgm->wav, 0x30, SEEK_SET);
}
	

	
void PlayMusic(BGM *bgm)
{
	bgm->ret = fread(bgm->chunk, 1, sizeof(bgm->chunk), bgm->wav);
	if (bgm->ret > 0)
	{
		audsrv_wait_audio(bgm->ret);
		audsrv_play_audio(bgm->chunk, bgm->ret);
	}
	
}

void UnloadMusic(BGM *bgm)
{
	fclose(bgm->wav);

	printf("sample: stopping audsrv\n");
	//audsrv_quit();

	printf("sample: ended\n");

}
