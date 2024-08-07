% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/sample_sets.R
\name{collapse_selection}
\alias{collapse_selection}
\alias{collapse_selection,loxcode_experiment-method}
\title{Collapse selected samples (v2)}
\usage{
collapse_selection(
  lox,
  count_matrix = "all_samples",
  code_set = "all_codes",
  index,
  name = NULL,
  union = TRUE,
  average = FALSE
)

\S4method{collapse_selection}{loxcode_experiment}(
  lox,
  count_matrix = "all_samples",
  code_set = "all_codes",
  index,
  name = NULL,
  union = TRUE,
  average = FALSE
)
}
\arguments{
\item{lox}{loxcode_experiment object}

\item{count_matrix}{sample set/ count_matrix}

\item{code_set}{code set}

\item{index}{indices of samples to collapse}

\item{name}{new sample name}

\item{union}{boolean: use union or intersection of samples}

\item{average}{boolean: use average of sum of counts}
}
\value{
updated loxcode_experiment object
}
\description{
Collapse selected samples (v2)
}
\examples{
# Load required packages
library(loxcodeR)

# Example usage
# Assuming lox, count_matrix, code_set, index, name, union, and average are defined and have the required structure
datards <- system.file("extdata","data-2024-05-20.rds",package="loxcodeR")
lox <- readRDS(datards)
collapse_selection(lox, count_matrix = "all_samples", code_set = "all_codes", index = c(1, 3), name = NULL, union = TRUE, average = FALSE)
}
