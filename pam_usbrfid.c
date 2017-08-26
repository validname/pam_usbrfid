#define PAM_SM_AUTH

#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

#include <stdio.h>
#include <syslog.h>
#include <stdarg.h>
#include <string.h>

#define MODULE_NAME	"pam_usbrfid"
#define BUFSIZE		256
#define	USER		"testuser"
#define PASSWORD	"12345"

//#define DEBUG

#ifdef DEBUG
void debug(char *format, ...) {
	char buf[BUFSIZE];
	va_list args;

	va_start (args, format);

	vsnprintf(buf, BUFSIZE, format, args);
	printf("%s\n", buf);
	openlog(MODULE_NAME, LOG_CONS|LOG_PID, LOG_AUTH);
	syslog(LOG_DEBUG, buf);

	va_end (args);
}
#else
static void debug() {
	return;
}
#endif

int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	const char *user = NULL;
	const char *password = NULL;
	int retval;

	retval = pam_get_user(pamh, &user, NULL);
	if (retval != PAM_SUCCESS || user == NULL) {
		return(PAM_IGNORE);
	}
	debug("pam_sm_authenticate(): user '%s'", user);

	retval = pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);
	if (retval != PAM_SUCCESS) {
		debug("pam_get_authtok() returned %d!", retval);
		return(PAM_IGNORE);
	}
	if (password == NULL) {
		debug("pam_sm_authenticate(): empty password");
	} else {
		debug("pam_sm_authenticate(): password = '%s'", password);
	}

	if (!strcmp(user,USER )) {
		if (!strcmp(password, PASSWORD)) {
			debug("return PAM_SUCCESS to grant access");
			return(PAM_SUCCESS);
		}
	}

	return(PAM_IGNORE);
}

int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	return(PAM_IGNORE);
}

