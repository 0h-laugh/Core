/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:58:11 by olaf              #+#    #+#             */
/*   Updated: 2025/03/15 20:48:18 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(void)
{
    char *lyrics[] = {
        "[Intro]",
        "Are you alright?",
        "I'm alright, I'm quite alright",
        "And my money's right",
        "(8) Yeah",
        "Countin' them bands all way to the top 'til they be fallin' over",
        "Countin' them bands on my way to the top 'til it's fallin' over",
        "",
        "[Chorus]",
        "I don't really care if you cry",
        "On the real, you should've never lied",
        "Should've saw the way she looked me in my eyes",
        "She said, \"Baby, I am not afraid to die\"",
        "Push me to the edge",
        "All my friends are dead, push me to the edge",
        "All my friends are dead, push me to the edge",
        "All my friends are dead, push me to the edge",
        "",
        "[Verse 1]",
        "Phantom that's all red, inside all white",
        "Like something you ride a sled down, I just want that head",
        "My bracelet Hermes, her bracelet Hermes now",
        "Everybody got the same swag now",
        "Watch the way that I tear it down",
        "Stacking my bands all the way to the top",
        "All the way till my bands falling over",
        "Every time that you leave your spot",
        "Your girlfriend call me like, \"Come on over\"",
        "I like the way that she treat me, gon' leave you, won't leave me, I call it that Casanova",
        "She say I'm insane, yeah, I might blow my brain out",
        "Xanny, help the pain, yeah",
        "Please, Xanny, make it go away",
        "I'm committed, not addicted, but it keep control of me",
        "All the pain, now I can't feel it, I swear that it's slowing me, yeah",
        "",
        "[Chorus]",
        "I don't really care if you cry",
        "On the real, you should've never lied",
        "Saw the way she looked me in my eyes",
        "She said, \"I am not afraid to die\"",
        "Yeah, all my friends are dead",
        "Push me to the edge, yeah, all my friends are dead",
        "Yeah, ooh, push me to the edge",
        "All my friends are dead, yeah, all my friends are dead, yeah",
        NULL
    };

    int i = 0;
    while (lyrics[i])
    {
        printf("%s\n", lyrics[i]);   // Wypisanie tekstu w terminalu
        fflush(stdout);

        // Odczytanie na głos - `espeak` dla Linuxa, `say` dla macOS
        char command[256];
        snprintf(command, sizeof(command), "espeak \"%s\" --stdout | aplay", lyrics[i]);  // Linux
        // snprintf(command, sizeof(command), "say \"%s\"", lyrics[i]); // macOS (odkomentuj, jeśli masz macOS)
        system(command);

        sleep(1);  // Opóźnienie między linijkami
        i++;
    }

    return 0;
}
