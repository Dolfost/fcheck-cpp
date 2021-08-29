// messages/default.h -- default fcheck error messages
// to make program use it, rename file to current.h

#define FCHECK_MESSAGE_H

#define FCHECK_PREFIX 		"ERROR: "
#define FCHECK_FAILED_TO_OPEN 	"Could not open the file \"" << filename << "\".\n"
#define FCHECK_EOF 		"End of file \"" << filename << "\" reached.\n"
#define FCHECK_FAIL		"Input from file \"" << filename << "\" terminated by data missmatch.\n"
#define FCHECK_BAD		"Input from file \"" << filename << "\" terminated for unknown reason.\n"
#define FCHECK_EOF_MSG		"End of file \"" << filename << "\" reached.\n"

// reference: 
// 		'filename' -- pointer to char array or char array passed to function
