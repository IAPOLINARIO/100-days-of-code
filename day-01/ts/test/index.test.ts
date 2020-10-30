import {expect, test} from '@oclif/test'

import cmd = require('../src')

describe('day-01', () => {
  test
  .stdout()
  .do(() => cmd.run([]))
  .it('runs age converter without year', ctx => {
    expect(ctx.stdout).to.contain('valid year')
  })

  test
  .stdout()
  .do(() => cmd.run(['wrong']))
  .it('runs age converter invalid year', ctx => {
    expect(ctx.stdout).to.contain('valid year')
  })

  test
  .stdout()
  .do(() => cmd.run(['20']))
  .it('runs age converter with year 20', ctx => {
    expect(ctx.stdout).to.contain('7300')
  })
})
