% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/loxcode_experiment.R
\name{delete_codeset}
\alias{delete_codeset}
\alias{delete_codeset,loxcode_experiment-method}
\title{Deletes a specified codeset from a loxcode experiment}
\usage{
delete_codeset(x, n)

\S4method{delete_codeset}{loxcode_experiment}(x, n)
}
\arguments{
\item{x}{loxcode_experiment object}

\item{n}{name of the codeset to be deleted}
}
\value{
new loxcode_experiment object with a new codeset
}
\description{
Deletes a specified codeset from a loxcode experiment
}
\examples{
# Create a sample loxcode_experiment object
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)


# Delete a codeset named 'example_codeset' from the loxcode experiment
lox_updated <- delete_codeset(lox, 'all_codes')
}
